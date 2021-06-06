# Rog
Your go to esoteric programming language.

### Why?
This was just to practice my C and build good coding [habits](https://www.youtube.com/watch?v=dQw4w9WgXcQ)

### But Why?
You should use it (actually you probably shouldn't) for impressing your friends.

### Features
- Simple (it has literally only one job)
- Fast(ish) (uses `fopen` to interpret)
- Small and simple to understand docs (really because it is so simple)
- Interpreted (will probably implement a compiler sometime)

### You probably shouldn't use it for ...
- Scalable programs (this thing does not scale well)
- Easy to understand programs (even I, as the creator of this smoking pile of crap, have a hard time understanding this mess)
- Anything involving basic logic (I bet someone out there could do some maths with it, not me)

# Tutorial
Rog's one function (for now) is to print stuff to the console.

Let's learn it by building a ~~simple~~ "Hello, world!" program.

First, create the file, we'll call this `hello_world.rg`

There are 26 letters in the English alphabet, _abcdefghijklmnopqrstuvwxyz_. Each letter has a corresponding number, for example, _a is to 1, b is to 2, c is to 3_ and so on. Think of it as a key to value pair, if the number _one_ is the **key**, then the letter _a_ is the **value**.

We start from zero, zero is cool, `+` increments the key, `-` decrements the key ID.
Therefore `++` is two, printing the letter `b`

Now, what if you wanted capital letters, you decided that you were too cool for little letters. Then you would simply add `c` in front of the increment/decrement symbols.
So, `c++` prints the letter `B`.

If you wanted a new letter, just simply go to a new line. The example below prints out the text `Rog`.
```
c++++++++++++++++++
+++++++++++++++
+++++++
```

Spcecial characters have a special method to handle them, special characters use the `/` operator and a number. Check the [char table](https://github.com/tominekan/rog) for more.
This means that to get a space character printed out, enter a new line and type in `/0`
Now that you have the information, try typing `"Hello, World!"`, don't forget the newline character.





Feeling stuck (that's the point)? Try this!
```
c++++++++
+++++
++++++++++++
++++++++++++
+++++++++++++++
/30
/0
c+++++++++++++++++++++++
+++++++++++++++
++++++++++++++++++
++++++++++++
++++
/4
/2
```