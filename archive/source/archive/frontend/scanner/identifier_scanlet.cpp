#include <unordered_map>

#include "archive/frontend/scanner/identifier_scanlet.hpp"
#include "archive/common/utility.hpp"
#include "archive/common/assert.hpp"

using namespace archive;
using namespace archive::frontend;
using namespace archive::frontend::detail::scanner;

auto IdentifierScanlet::candidate(Source& source) const -> bool
{
    return !source.at_end() && utility::is_alpha(*source.peek());
}

auto IdentifierScanlet::scan(Source& source) const -> Token
{
    ASSERT(candidate(source), "invalid identifier candidate");
    auto location = source.location();
    auto name     = identifier_name(source);
    auto type     = identifier_type(name);
    return { type, location, std::move(name) };
}

auto IdentifierScanlet::identifier_name(Source& source) -> std::string
{
    using utility::is_alpha;
    using utility::is_digit;

    auto name = std::string();
    while (!source.at_end() && (is_alpha(*source.peek()) || is_digit(*source.peek())))
        name += *source.consume();

    return name;
}

auto IdentifierScanlet::identifier_type(std::string_view name) -> Token::Type
{
    static const auto keywords = std::unordered_map<std::string_view, Token::Type>
    {
        // keywords
        { "as",       Token::Type::As       },
        { "break",    Token::Type::Break    },
        { "case",     Token::Type::Case     },
        { "class",    Token::Type::Class    },
        { "continue", Token::Type::Continue },
        { "default",  Token::Type::Default  },
        { "delete",   Token::Type::Delete   },
        { "do",       Token::Type::Do       },
        { "else",     Token::Type::Else     },
        { "enum",     Token::Type::Enum     },
        { "false",    Token::Type::False    },
        { "for",      Token::Type::For      },
        { "fun",      Token::Type::Fun      },
        { "if",       Token::Type::If       },
        { "import",   Token::Type::Import   },
        { "lambda",   Token::Type::Lambda   },
        { "let",      Token::Type::Let      },
        { "module",   Token::Type::Module   },
        { "new",      Token::Type::New      },
        { "nil",      Token::Type::Nil      },
        { "return",   Token::Type::Return   },
        { "switch",   Token::Type::Switch   },
        { "true",     Token::Type::True     },
        { "var",      Token::Type::Var      },
        { "while",    Token::Type::While    },

        // basic data types
        { "bool",     Token::Type::Bool     },
        { "char",     Token::Type::Char     },
        { "void",     Token::Type::Void     },

        // signed integer types
        { "i8",       Token::Type::I8       },
        { "i16",      Token::Type::I16      },
        { "i32",      Token::Type::I32      },
        { "i64",      Token::Type::I64      },
        { "isz",      Token::Type::Isz      },

        // unsigned integer types
        { "u8",       Token::Type::U8       },
        { "u16",      Token::Type::U16      },
        { "u32",      Token::Type::U32      },
        { "u64",      Token::Type::U64      },
        { "usz",      Token::Type::Usz      },

        // floating point types
        { "f32",      Token::Type::F32      },
        { "f64",      Token::Type::F64      },
    };

    return keywords.contains(name)
         ? keywords.at(name)
         : Token::Type::Identifier;
}
