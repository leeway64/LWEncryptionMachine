build-all:
	cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=ninja -G Ninja -S . -B ./cmake-build-release
	cmake --build ./cmake-build-release --target LWEncryptionMachine
	cmake --build ./cmake-build-release --target test_suite

run-tests:
	bin/test_suite
