def set_int_to_42(x):
    x = 42

y = 41
set_int_to_42(y)

print(y)


class Pair:
    fst = 0
    snd = 0

def set_fst_of_pair_to_42(p):
    p.fst = 42

y = Pair()
y.fst = 41
set_fst_of_pair_to_42(y)

print("{ " + str(y.fst) + ", " + str(y.snd) + " }")
