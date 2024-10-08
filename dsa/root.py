# Step 1: Start (No code needed)

# Step 2: Declare variables
a = float(input("Enter coefficient a: "))
b = float(input("Enter coefficient b: "))
c = float(input("Enter coefficient c: "))

# Step 3: Calculate discriminant
D = b**2 - 4*a*c

# Step 4: If D ≥ 0
if D >= 0:
    r1 = (-b + D**0.5) / (2*a)
    r2 = (-b - D**0.5) / (2*a)
    print(f"Root 1 (r1): {r1}")
    print(f"Root 2 (r2): {r2}")
else:
    # Step 4 (Else): Calculate real and imaginary parts
    rp = -b / (2*a)
    ip = (-D)**0.5 / (2*a)
    print(f"Root 1 (rp + j(ip)): {rp} + {ip:.2f}j")
    print(f"Root 2 (rp - j(ip)): {rp} - {ip:.2f}j")

# Step 5: Stop (No code needed)