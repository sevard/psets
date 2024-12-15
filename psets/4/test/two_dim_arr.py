#!/usr/bin/env python3

arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]


indx = 0
for i in range(3):
    for el in arr:
        print(el[indx], end=" ")
    indx += 1
    print()

# indx +=1
# for el in arr:
#     print(el[indx], end=" ")
# print()

# indx +=1
# for el in arr:
#     print(el[indx], end=" ")
# print()
