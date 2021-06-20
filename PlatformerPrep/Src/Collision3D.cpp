#include <Collision3D.hpp>

using namespace Core::Maths;

void Collision3D::globalToLocal(
	vec3& P_prime, const referential3& localRef, const vec3 P
)
{
	// when i rotate the cube, I will be rotating the localRef i, j, and k values
	vec3 point = P - localRef.origin;

	P_prime.x = dotProduct(point, localRef.i);
	P_prime.y = dotProduct(point, localRef.j);
	P_prime.z = dotProduct(point, localRef.k);

}

bool Collision3D::segmentPlane(
	const vec3& ptA, const vec3& ptB,
	const Plane& plane, const vec3& ptIntersect,
	const vec3& ptNormIntersect
)
{
	float result = dotProduct(ptB - ptA, ptNormIntersect);
	return true;
}

bool Collision3D::segmentSphere(
	const vec3& ptA, const vec3& ptB,
	const Sphere& sphere, const vec3& ptIntersect,
	const vec3& ptNormIntersect
)
{
	return true;
}

bool Collision3D::orientedRectSphere(
	const referential3& globalRef, const OrientedBox& Box,
	const Sphere& Sphere
)
{

	return true;
}

bool Collision3D::orientedRects(
	const OrientedBox& BoxA, const OrientedBox& BoxB
)
{
	return true;
}