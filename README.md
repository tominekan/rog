# Rog
Your go to esoteric programming language.
- [Why](#why)
- [But Why?](#but-why)
- [Features](#features)
- [You probably shouldn't use this for](#you-probably-shouldnt-use-it-for)
- [Installation](#installation)
- [Tutorial](#tutorial)


### Why?
This was just to practice my C and build good coding [habits](https://www.youtube.com/watch?v=dQw4w9WgXcQ). This means that I will probably not work on it past the first version.

### But Why?
You should use it (actually you probably shouldn't) for impressing your friends.

### Features
- Simple (it has literally only one job)
- Fast(ish) (uses `fopen` for buffered FileIO)
- Small and easy to understand docs (really because it is so simple)
- Interpreted (no build systems needed for this project)

### You probably shouldn't use it for ...
- Scalable programs (this thing **does not** _scale_)
- Easy to understand programs (this is pretty esoteric)
- Anything involving basic logic (it has _only one_ job)

# Installation
**NOTE: This is not guaranteed to work on operating systems other than Linux. On that note, it _may_ work on macOS but most definitely _will not_ work on Windows** 

With only three dependencies, it's actually pretty easy to install rog.

- `gcc` for a C compiler. You can change this by going to the makefile and changing the `CC` variable
- `make` to build the compiled files
- `install` (in GNU coreutils) to install the files

First download the project to your local machine using

```sh
git clone https://github.com/tominekan/rog.git
```

Alternatively, you can download a `tar` or `zip` archive of the project from the releases page.

To check if your system has the dependencies to install rog, go to the rog directory and run the `checks.sh` file.

```sh
cd rog
./checks.sh
```

To build the project, run

```sh
make
```

To install, you need root permissions (by default it installs the file to `/usr/local/bin`).

```sh
sudo make install
```

Or, you can change the directory by going to the `install` target in the Makefile and changing the where the rog binary is installed.

# Tutorial
Rog's one function is to print stuff to the console.

Let's learn it by building a ~~simple~~ "Hello, world!" program.

First, create a file, in this example, we'll call this `hello_world.rg`

There are 26 letters in the English alphabet, _abcdefghijklmnopqrstuvwxyz_. Each letter has a corresponding number, for example, _a is to 1, b is to 2, c is to 3_ and so on. Think of it as a key to value pair, if the number _one_ is the **key**, then the letter _a_ is the **value**. **In rog, certain combinations of characters arranged in a logical (but totally nonsensical) sequence are given to rog to produce a key, and rog produces (and prints) the value from them.**

We start counting from 0 (zero based indexing), `+` increments the key ID for alphabetic charcters.
Therefore `+` is _1_ or the letter `a`, `++` is _2_ or the letter `b`, `+++` is _3_ or the letter `c`, going on and on till `z`.

Now, what if you wanted capital letters. You would simply add `c` in front of the increment/decrement symbols.
So, `c+` prints the letter `A`, `c++` prints the letter `B` and so on.

If you wanted a new letter, just simply go to a new line. The example below prints out the text `Rog`.

```
c++++++++++++++++++
+++++++++++++++
+++++++
```
To run the code, type 

```sh
rog <file_name>.rg
```

Spcecial characters have a special method to handle them, they use the `/` operator and a number. Check the [Character Table](https://github.com/tominekan/rog/blob/main/char_table.md) for all the characters.
This means that to get a space character printed out, enter a new line and type in `/0`.

Now that you have the information (and the [Character Table](https://github.com/tominekan/rog/blob/main/char_table.md)), try printing `"Hello, World!"` to the console. Don't forget the newline character.


Feeling stuck? Check [this](https://github.com/tominekan/rog/blob/main/hello_world.rg) out.