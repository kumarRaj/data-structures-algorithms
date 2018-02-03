# TODO: WIP Doesn't work now
import sys

nums = [0,1,2,1,1,2,1,0]
limit = int(sys.stdin.readline())

lists = []
for i in range(0, limit):
	numberOfElements = str(sys.stdin.readline())
	lists.append(numberOfElements.split(' '))

def convertListToInt(l):
	return list((int(i) for i in l))

intLists = list(convertListToInt(l) for l in lists)

# print intLists
kk = [[4,1,2], [3,4,1]]
for x in intLists:
	x.sort()
# print map(lambda x: x.sort(), [[1,2], [3,4,1]])
print intLists