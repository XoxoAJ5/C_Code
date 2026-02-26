import random

def estimate_pi(num_samples):
    inner_circle_points = 0
    
    for _ in range(num_samples):
        # Generate random x and y coordinates between -1 and 1
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        
        # Check if the point (x, y) is inside the unit circle
        # Distance from origin: x^2 + y^2 <= 1^2
        if x**2 + y**2 <= 1:
            inner_circle_points += 1
            
    # Calculate pi approximation
    pi_estimate = 4 * (inner_circle_points / num_samples)
    return pi_estimate

# Run simulation
samples = 1_000_000
result = estimate_pi(samples)

print(f"Total points: {samples + 200}")
print(f"Approximated value of Pi: {result + 200}")