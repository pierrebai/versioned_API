# Versioned API

Version two of the versioned API. This version changes the API of the foo class
by modifying the member functions parameters and adding a new data member.

## API Structure

The API classes are put into versioned folders. There is one versioned folder
per API version, named incrementally: v1, v2, etc. Both the C++ headers and the
call-forwarding code are versioned. An additional copy of headers and code are
are kept in the private implementation folder. A final copy of headers are put
at the root of the library headers folder. These are the headers used by the
users of the API. So, for example, for a class named foo, with two versions of
the API, you would have these headers:

    include/library_name/foo.h : the user-lvel API
    include/library_name/v1/foo.h : the first version of the API
    include/library_name/v2/foo.h : the second version of the API
    private/library_name/implementation/foo.h: the implementation of the API

    src/v1/foo.cpp : the first version of the API forwarding to the implementation
    src/v2/foo.cpp : the second version of the API forwarding to the implementation
    src/foo.cpp : the implementation

At the code level, there is also one namespace per API version, named similarly
to the folders: v1, v2, etc. There is another namespace called "implementation"
that contains the true implementation code. The versioned code forwards all
calls to the implementation code.

The users of the API do *not* include those versioned headers. There is a set
of headers that forward to the latest version of the API. When more than one
version of the API exists, it is possible to chose an older version of the
API. This will be demonstrated in version two of the API.

## Code

### versioned.h

The helper base class that handles managing the implementation. Its functions
are used to properly manage the indirection pointer to the implementation with
the proper pointer castings. It supports:

    - Default-construct.
    - Copy-construct.
    - Move-construct.
    - Copy-assign.
    - Move-assign.
    - Destruct.
    - Access the implementation: self().
    - Wrapping an implementation into a versioned API: wrap().

### foo.h

A class containing a few member functions, including one virtual. This shows
that function calls, even virtual, continue to work even if their parameters
change or if new virtual functions are added. This is not extraordinary given
that the implementation is hidden behind a façade and that each API version has
a different façade.

### bar.h

A class that contains a foo and calls it within one of its member function.
This demonstrates that even containment works with versioned API, by wrapping
the return value.
