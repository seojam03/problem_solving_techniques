import random

# 1부터 100000까지 랜덤 수 10000개 생성 (중간에 작은 수 포함)
numbers = []
for _ in range(80000):
    # 10% 확률로 1~99 사이 작은 수, 90%는 1~100000 범위
    if random.random() < 0.1:
        numbers.append(random.randint(1, 99))
    else:
        numbers.append(random.randint(1, 100000))

    # numbers.append(random.randint(1, 99))
    

# 파일에 저장 (숫자는 공백으로 구분됨)
with open("random_numbers.txt", "w") as f:
    f.write(" ".join(map(str, numbers)))

print("random_numbers.txt 파일이 생성되었습니다.")
