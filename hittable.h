#ifndef HITTABLE_H
#define HITTABLE_H
#include "ray.h"
class hit_record {
    public:
    point3 p;
    vec3 normal;
    vec3 outward_normal;
    double t;
    bool front_face;
    void set_front_face(const ray& r,const vec3& outward_n){
        front_face = dot(r.direction(),outward_n) < 0;
        normal = front_face ? outward_n : -outward_n;
    }

}; 
class hittable{
    public:
    virtual ~hittable() = default;
    virtual bool hit (const ray& r,interval ray_t,hit_record& rec) const = 0;
};


#endif