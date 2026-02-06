Project: This project implements a vector-based ray-casting engine to visualise a maze from a first-person perspective, using linear algebra, trigonometry, and real-time rendering techniques in C - developed by imutavdz and rbagin:

Description:

a ray-casting engine

using 2D vectors + linear algebra + trigonometry

to create a pseudo-3D first-person perspective

rendered in real time using MLX42

Engine: 
represents the player view with direction and camera plane vectors

casts one ray vector per screen column

computes intersections using vector stepping (DDA)

projects wall height using perpendicular distance (vector projection)

maps texture coordinates using vector math