#pragma once

#include <vector>

#include <raylib/raylib.h>

#include <Core.h>

namespace Core
{
    namespace Maths
    {
        struct line
        {
            vec2 point;
            vec2 vector;
        } ;

        struct segment
        {
            vec2 pointA;
            vec2 pointB;
        } ;

        struct circle
        {
            vec2 center;
            float radius;
        } ;

        struct rectangle
        {
            vec2 center;
            float width;
            float height;
        } ;

        struct orientedRect
        {
            rectangle rect;
            float angle;
        } ;

        struct referential2
        {
            vec2 origin;     // l'origine locale
            vec2 vector_i;  // x unit vector
            vec2 vector_j;  // y unit vector
            float    angle;     // l'angle de rotation du référentiel par rapport au référentiel parent (le World)
        } ;

        struct convexPolygon
        {
            referential2            local;
            std::vector<vec2>   vertices;
        } ;

        struct range  // contient l'intervalle des quantités de projection d'une figure géométrique sur un axe
        {
            float min;
            float max;
        } ;

        // le référentiel 2D d'un gameobject , défini par la position d'origine et deux vecteurs unitaires orthonormés . 
        //La structure peut également contenir l'angle de rotation du référentiel par rapport au référentiel parent (le World)


        struct referential3
        {
            vec3 origin;     
            vec3 i;  
            vec3 j; 
            vec3 k;
            float    angle;     
        };


        struct Plane
        {
            Plane(vec3& ptA, vec3& ptB, vec3& ptC);

            Plane(vec3& normal, vec3& ptIntersect);

            Plane(vec3& normal, float d);

            void myDrawPlane(Color& color);

            vec3 normal;
            float d;  // la distance algebraique entre origin (O) et le plan (P)
        };

        struct OrientedBox
        {
            referential3 local;
            vec3 extensions;  // length of x, y et z
        };

        struct Sphere
        {
            Sphere() = default;

            Sphere(vec3 _omega)
            {
                omega = _omega;
            }

            float r = 1.f;
            vec3 omega = { 0.f, 0.f, 0.f };
        };

        struct CylindreFini
        {
            CylindreFini() = default;

            float r;
            vec2  axe;
        };

        struct CylindreInfini
        {
            CylindreInfini() = default;

            float r;
            vec2  axe;
        };
    }
}


