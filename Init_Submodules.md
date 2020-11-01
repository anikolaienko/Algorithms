# Initialize Google Test library
* We are not using `git submodule` feature
* We just clone repo as subdirectory.
* We will not modify it and use stable release version.

```bash
git clone https://github.com/google/googletest.git
cd googletest
git checkout release-1.10.0
cd ..
```