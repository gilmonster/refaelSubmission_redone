import subprocess


def build_cpp_project(source_directory, build_directory):
    try:
        # Run CMake to configure the build
        cmake_configure = ["cmake", source_directory]
        subprocess.run(cmake_configure, cwd=build_directory, check=True)

        # Run the build process (make, ninja, or other build system based on the CMake generator)
        cmake_build = ["cmake", "--build", "."]
        subprocess.run(cmake_build, cwd=build_directory, check=True)

        print("Build successful!")
    except subprocess.CalledProcessError as e:
        print(f"Build failed: {e}")


if __name__ == "__main__":
    # Replace the paths below with your source and build directory paths
    source_dir = r"C:\Users\USER\source\repos\RefaelSubmission2"
    build_dir = r"C:\Users\USER\source\repos\RefaelSubmission2\build"

    build_cpp_project(source_dir, build_dir)
