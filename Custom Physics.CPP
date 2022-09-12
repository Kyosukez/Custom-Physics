struct AABB
{
    Vec2 min;
    Vec2 max;
};

bool AABBvsAABB(AABB a, AABB b)
{
    //Exit with no intersection if found separated along an axis
    if(a.max.x < b.min.x or a.min.x > b.max.x) return false
    if(a.max.y < b.min.y or a.min.y > b.max.y) return false

    //No separating axis found, therefor there is at least one overlapping axis
    return true
}

struct Circle
{
    float radius
    Vec position
};

float Distance( Vec2 a, Vec2 b )
{
    return sqrt((a.x - b.x)^2 +(a.y - b.y)^2)
}

bool CirclevsCircleUnoptimized( Circle a, Circle b )
{
    float r = a.radius + b.radius
    return r < Distance(a.position, b.position)
}

bool CirclevsCircleOptimized( Circle a, Circle b )
{
    float r = a.radius + b.radius
    r *= r
    return r < (a.x + b.x)^2 + (a.y + b.y)^2
}

//Given two objects A and B
e = min( A.restitution, B.restitution )

void ResolveCollision( Object A, Object B)
{
    //Calculate relative velocity
    Vec2 rv = B.velocity - A.velocity

    //Calculate relative velocity in terms of the normal direction 
    float velAlongNormal = DorProduct( rv, normal)

    //Do not resolve if velociies are separating
    if(velAlongNormal > 0)
        return;

    //Calculate restitution
    float e = min( A.restitution, B.restitution)

    //Calculate impulse scalar
    float j = -(1 + e) * velAlongNormal
    j /= 1 / A.mass + 1 / B.mass

    //Apply impulse
    Vec2 impulse = j * normal
    A.velocity -= 1 / A.mass * impulse
    B.velocity += 1 / B.mass * impulse
}

A.inv_mass = 1 / A.mass

float mass_sum = A.mass + B.mass
float ratio = A.mass / mass_sum
A.velocity -= ratio * impulse

ratio = A.mass + B.mass
B.velocity += ratio * impulse

if(A.mass ==0)
    A.inv_mass = 0
else
    A.inv_mass = 1 / A.mass

void PositionalCorrection( Object A, Object B)
{
    const float percent = 0.2 //usually 20% to 80%
    Vec2 correction = penetrationDepth / (A.inv_mass + B.inv_mass)) * percent * n
    A.position -= A.inv_mass * correction
    B.position += B.inv_mass * correction
}

void PositionalCorrection( Object A, Object B)
{
    const float percent = 0.2 //usually 20% to 80%
    const float slop = 0.01 // usually 0.01 to 0.1
    Vec2 correction = max( penetration - k_slop, 0.0f ) / (A.inv_mass + B.inv_mass)) * percent * n
    A.position -= A.inv_mass * correction
    B.position += B.inv_mass * correction
}

