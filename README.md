## IGL C++ -> JS

To compile a normal binary you can use (as per the instructions in [the igl documentation](https://github.com/libigl/libigl/blob/master/README.md))

_note: this assumes libigl is in a sibling directory_

```
g++ -std=c++11 -I/usr/local/include/eigen3 -I../libigl/include/ hello.cpp -o hello
```

But, to compile an Emscripten version, use:

```
em++ -std=c++11 -I/usr/local/include/eigen3 -I../libigl/include/ hello.cpp -o hello
```

To build the web version use:

```
em++ -std=c++11 -I/usr/local/include/eigen3 -I../libigl/include/ hello.cpp -o index.html
```

----

## Testing Bindings

Run:

```
emcc -I ../libigl/include -I/usr/local/include/eigen3 --bind -o hello_binding.js hello_binding_example.cpp
```

to generate a new `hello_binding.js` file, which you can see the results of if you serve & open `hello_binding_example.html`
