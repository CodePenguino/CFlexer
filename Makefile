DIR = "./build/."

all:
ifneq ($(wildcard ./build/.),)
	@echo "Found build folder, no need for me to create it!"
	cd build && cmake .. && cmake --build . && cd ../
else
	@echo "Did not find build folder, i'll create it for you..."
	mkdir build && cd build && cmake .. && cmake --build . && cd ../
endif

run:
ifneq ($(wildcard ./build/.),)
	@echo "Found build folder, no need for me to create it!"
	cd build && cmake .. && cmake --build . && ./CFlexer && cd ../
else
	@echo "Did not find build folder, i'll create it for you..."
	mkdir build && cd build && cmake .. && cmake --build . && ./CFlexer && cd ../
endif

clean:
ifneq ($(wildcard ./build/.),)
	@echo "Found build folder, deleting it..."
	rm -rf build
else
	@echo "Did not find build folder, you should be fine"
endif
