n = int(input())

strs = []
dicl = []
uni = {}
new_dic = {}
new_str = ''
for i in range(n):
    d = input()
    strs.append(d)
    a = {}
    for w in d:
        if w not in a.keys():
            a[w] = 1
        else:
            a[w] += 1
    dicl.append(a)

uni = set.intersection(*map(set,strs))
for i in uni:
    new_dic[i] = 10000000000

for l in uni:
    for i in range(n):
        if l in dicl[i]:
            if new_dic[l] > dicl[i][l]:
                new_dic[l] = dicl[i][l]
        

myKeys = list(new_dic.keys())
myKeys.sort()
sorted_dict = {i: new_dic[i] for i in myKeys}
for i in sorted_dict.keys():
    new_str += i*sorted_dict[i] 



print(new_str)