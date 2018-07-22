#!/bin/python



def do_prime(L,result_list):
    if not isinstance(L, list):
        raise TypeError("input parameter shall be a list, %s" % type(L))

    if len(L) == 0:
        print "this is a empty list"
        return L

    temp = L
    if L[0] != 2:
        temp = [2] + temp

    return eratosthenes_prime(temp, result_list)

def eratosthenes_prime(L, result_list):
    if L == []:
        return;

    first_prime = L[0]
    result_list.append(L[0])
    return eratosthenes_prime(filter(lambda x : x % first_prime != 0, L),
                               result_list) 

if __name__ == "__main__":
    list_a = [2, 3, 4, 24, 5, 42, 215, 12, 52, 64, 62, 69, 97, 87, 46, 47, 23, 37, 11, 17, 61]
    uniq_sorted_list = list(set(list_a))
    uniq_sorted_list.sort()
    result_list = []
    prime_list = do_prime(uniq_sorted_list, result_list)
    print result_list
