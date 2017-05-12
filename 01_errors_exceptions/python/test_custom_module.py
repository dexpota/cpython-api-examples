from custom import value_error, custom_error, error
from nose.tools import *


@raises(ValueError)
def test():
    value_error()


@raises(error)
def test_custom():
    custom_error()
