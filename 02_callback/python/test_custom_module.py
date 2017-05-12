from custom import call_callback, set_callback

def foo():
    print("This is Python.")

set_callback(foo)
call_callback()