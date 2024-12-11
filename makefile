default:
	make release

release:
	cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
	cmake --build build

debug:
	cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

clean:
	cmake -E remove_directory build
	cmake -E remove_directory bin

help:
	@echo ""
	@echo " supported make recipes:"
	@echo "     - default   Invokes 'make release'"
	@echo "     - debug     Builds a debug version of the program"
	@echo "     - release   Builds a release version of the program"
	@echo "     - clean     Cleans up compiled binaries and build artifacts"
	@echo "     - help      Lists all supported make recipes"
	@echo ""
	@exit
