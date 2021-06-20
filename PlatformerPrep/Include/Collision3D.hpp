#pragma once

#include <primitives.h>
#include <Core.h>



namespace Collision3D
{

	/*
		p - point being simplified
		localRef - local referential that point p is being simplified to
		O - Origin (global ref)
		P_prime - point p after calculations (value we are returning)
	*/

	void globalToLocal(
		Core::Maths::vec3& P_prime, const Core::Maths::referential3& localRef, 
		const Core::Maths::vec3 P 
	);

	//void localToGlobal()

	bool segmentPlane(
		const Core::Maths::vec3& ptA, const Core::Maths::vec3& ptB,
		const Core::Maths::Plane& plane, const Core::Maths::vec3& ptIntersect,
		const Core::Maths::vec3& ptNormIntersect
	);

	bool segmentSphere(
		const Core::Maths::vec3& ptA, const Core::Maths::vec3& ptB,
		const Core::Maths::Sphere& sphere, const Core::Maths::vec3& ptIntersect,
		const Core::Maths::vec3& ptNormIntersect
	);

	bool orientedRectSphere(
		const Core::Maths::referential3& globalRef, const Core::Maths::OrientedBox& Box,
		const Core::Maths::Sphere& Sphere
	);

	bool orientedRects(
		const Core::Maths::OrientedBox& BoxA, const Core::Maths::OrientedBox& BoxB
	);


}