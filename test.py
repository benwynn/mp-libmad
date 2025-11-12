import mplibmad

print("start:")

mplibmad.hello("abc")

print("testing with integer instead of string:")
try:
  mplibmad.hello(42)
except TypeError:
  print(f"got expected TypeError exception, working as designed")
except Exception as e:
  print(f"got unexpected exception: {type(e).__name__}: {e.value}")

print("Done.")
