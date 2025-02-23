def sender():
    arr = [7, 23, 5, 17, 10]
    _sum = 0
    for i in arr:
        _sum += i
    arr.append(-_sum)

    return arr


def receiver(arr):
    _sum = 0
    for i in arr:
        _sum += i

    if _sum == 0:
        print("Yes ok")

    else:
        print("Error")


def main():
    arr = sender()
    receiver(arr)


if __name__ == "__main__":
    main()
