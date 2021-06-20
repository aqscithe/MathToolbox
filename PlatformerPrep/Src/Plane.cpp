#include <primitives.h>

using namespace Core::Maths;

Plane::Plane(vec3& ptA, vec3& ptB, vec3& ptC)
{
	vec3 ab = ptB - ptA;
	vec3 ac = ptC - ptA;
	normal = normalize(ab * ac / (magnitude(ab) * magnitude(ac)));  // produits vectorial 
	d = dotProduct(ptA, normal);
}

Plane::Plane(vec3& _normal, float d) : d(d)
{
	normal = normalize(_normal);
}

Plane::Plane(vec3& _normal, vec3& ptIntersect)
{
	normal = normalize(_normal);
	d = dotProduct(ptIntersect, normal); // vector OA | A = ptIntersect |  Im assuming origin(O) is 0,0,0
}

void Plane::myDrawPlane(Color& color)
{
	DrawPlane({ 0,0,0 }, {5, 5}, color);
	
}