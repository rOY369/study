"""
Mapping consists of applying a transformation function to an
iterable to produce a new iterable.

Items in the new iterable are produced by calling the
transformation function on each item in the original iterable.
"""

# map signature
# map(function, iterable[, iterable1, iterable2,..., iterableN])

# normal way to square numbers
list_of_num = [1, 2, 3, 4, 5]

squared = [n**2 for n in list_of_num]


# using map
def square(n):
    return n**2


squared = map(square, list_of_num)


"""
If you supply multiple iterables to map(),then the transformation
function must take as many arguments as iterables you pass in.
"""


def custom_print(text, name):
    return f"{text}, {name}"


texts = ["hi", "hello"]
names = ["dishant", "nishu"]

messages = map(custom_print, texts, names)
