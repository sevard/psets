
# n = 4_003_600_000_000_014
n = 1234567
x = n
l = ", ".join(reversed(list(str(n))))
print(l)

x = x // 10

while (x > 0):
    y = x % 10
    x = x // 100
    print(y, end=", ")
print()
