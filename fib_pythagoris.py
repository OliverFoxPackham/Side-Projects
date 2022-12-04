smallstart = 4
bigstart = 7

#makes fibonacci sequence with starting numbers
for numbers in range(2):
    newbig = smallstart + bigstart
    smallstart = bigstart
    bigstart = newbig
    print (smallstart)
print (bigstart)
newbig = smallstart + bigstart
print (newbig)
bigest = bigstart + newbig
print (bigest)

print ()

# pythagorean triplets generated
print (smallstart*bigest)
print (bigstart*newbig*2)
print (smallstart*newbig+bigstart*bigest)


print ()
# after squareing
print ((smallstart*bigest)**2)
print ((bigstart*newbig*2)**2)
print ((smallstart*newbig+bigstart*bigest)**2)

# double check regular way to show they're the same.
print (((smallstart*bigest)**2)+(bigstart*newbig*2)**2)
