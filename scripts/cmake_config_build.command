#!/bin/sh

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

cd $DIR
cd ..

source_folder=project
build_folder=build
if [ ! -d ./$build_folder ]; then
	mkdir $build_folder
fi
# -H indicates where the project sources are located
# -B indicates where the build folder will be located
cmake -H$source_folder -B$build_folder

cd $build_folder
#make -j4
#make install
cmake --build . --config Release -- -j4

exit 0