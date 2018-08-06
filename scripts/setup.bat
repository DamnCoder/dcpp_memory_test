@echo off

cd ..

set cmakeconfigure_folder=utilities/CMakeConfigure

if not exist %cmakeconfigure_folder% (
	git -c diff.mnemonicprefix=false -c core.quotepath=false submodule add -f https://github.com/DamnCoder/CMakeConfigure.git %cmakeconfigure_folder%
	git -c diff.mnemonicprefix=false -c core.quotepath=false submodule update --init utilities/CMakeConfigure
)

set newclassproject_folder=utilities/NewClassProject

if not exist %newclassproject_folder% (
	git -c diff.mnemonicprefix=false -c core.quotepath=false submodule add -f https://github.com/DamnCoder/NewClassProject.git %newclassproject_folder%
	git -c diff.mnemonicprefix=false -c core.quotepath=false submodule update --init utilities/NewClassProject
)

exit