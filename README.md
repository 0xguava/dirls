# dirls: A POSIX-Compliant Directory Traversal Utility

`dirls` is a lightweight, custom implementation of the classic Unix `ls -l` command written in C. It demonstrates core operating system concepts, specifically how 
user-space programs interact with the kernel's virtual file system (VFS) to extract and format inode metadata.

## Project Architecture

The project is separated into three distinct logic layers to maintain clean code and separation of concerns:

- `main.c`: The entry point. Handles command-line argument parsing and validation.
- `dir_ops.c` / `dir_ops.h`: The core systems logic layer. Manages directory streams and calls the `stat` struct.
- `format.c` / `format.h`: The presentation layer. Converts raw system bytes and time epochs into readable output strings.
- `Makefile`: Automates the build and linking process.

## Build Instructions

1. Clone or download the repository to your local machine.
2. Open your terminal and navigate to the project directory.
3. Compile the project using the provided Makefile:
   ```bash
   make
   ```
4. To clean up the compiled object files and the executable, run:
   ```bash
   make clean
   ```

## Usage

Run the compiled executable from the terminal. 

**List the current directory:**
```bash
./dirls
```

**List a specific target directory:**
```bash
./dirls /etc
./dirls /var/log
```

**Example Output:**
```text
drwxr-xr-x 2 root root  4096 Apr 05 14:30 app
-rw-r--r-- 1 user user   215 Apr 05 16:45 main.c
-rwxr-xr-x 1 user user 18432 Apr 05 16:46 dirls
```
