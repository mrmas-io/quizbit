@echo off
setlocal

REM Check if "--clean" argument is passed
if "%1"=="--clean" (
    REM Clean build directories and sub-directories
    echo Cleaning build directories...
    rmdir /s /q build
    exit /b
)

REM Create build directory if it doesn't exist
if not exist build mkdir build\database

REM Change to the build directory
cd build || exit /b

REM Run cmake to generate build files
cmake ..

REM Run the generated build system (e.g., Visual Studio solution)
cmake --build . --config Release

REM Check if the build was successful
if %errorlevel% equ 0 (
    echo Build successful. Running the program...
    REM Run the generated executable
    main.exe
) else (
    echo Build failed.
)
endlocal

















































REM @echo off
REM setlocal
REM Create build directory if it doesn't exist
REM if not exist build mkdir build/database
REM Change to the build directory
REM cd build || exit /b
REM Run cmake to generate build files
REM cmake ..
REM Run the generated build system (e.g., Visual Studio solution)
REM cmake --build . --config Release
REM Check if the build was successful
REM if %errorlevel% equ 0 (
    REM echo Build successful. Running the program...
    REM Run the generated executable
    REM main.exe
REM ) else (
    REM echo Build failed.
REM )
REM endlocal