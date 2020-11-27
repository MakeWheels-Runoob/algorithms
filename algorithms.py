import functools
import math
import random


def rand(start=0, end=1, digit=0):
    return round(random.random() * (end - start) + start, digit)


def sigmoid(x):
    return 1 / (1 + np.exp(x))


def summation(func, start=0, end=1, step=1):
    return functools.reduce(lambda x, y: x+y,
                            [func(i) for i in range(start, end, step)])


def quadrature(func, start=0, end=1, step=1):
    return functools.reduce(lambda x, y: x*y,
                            [func(i) for i in range(start, end, step)])


def reduce(func, operation, start=0, end=1, step=1):
    return functools.reduce(operation,
                            [func(i) for i in range(start,end,step)])


class Struct:
    def __init__(self, types='array'):
        self.type = types

    def insert(self, data, where):
        pass

    def pop(self):
        pass
    
    def __str__(self):
        return repr(self)
    
    def __repr__(self):
        return '';

    def __len__(self):
        return 0

    def front(self):
        return None

    def tail(self):
        return None
    top=tail
