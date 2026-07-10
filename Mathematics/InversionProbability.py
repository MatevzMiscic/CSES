from fractions import Fraction

n = int(input())
r = list(map(int, input().split()))

E = Fraction(0, 1)
for i in range(n):
    for j in range(i + 1, n):
        m = min(r[i], r[j])
        pairs = m * (m - 1) // 2
        if r[i] > r[j]:
            pairs += r[j] * (r[i] - r[j])
        E += Fraction(pairs, r[i] * r[j])

E *= 1_000_000
num, den = E.numerator, E.denominator
intpart, remainder = num // den, num % den

if 2 * remainder == den:
    if intpart % 2 == 1:
        intpart += 1
elif 2 * remainder > den:
    intpart += 1

ans = intpart / 1_000_000
print(f"{ans:.6f}")
