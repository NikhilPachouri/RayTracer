#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "color.h"
#include "camera.h"
#include "hittbales_list.h"
#include "sphere.h"
#include "rtweekend.h"
double hit_sphere(const point3& centre,double radius,const ray& r){
vec3 oc = centre - r.origin();
auto a = dot(r.direction(),r.direction());
auto b = -2.0 * dot(r.direction(),oc);
auto c = dot(oc,oc) - radius*radius;
auto discriminant = b*b - 4*a*c;
// return (discriminant >= 0);
if( discriminant < 0){return -1.0;} 
else {
  return    (-b-std::sqrt(discriminant))/(2.0*a);
}
};

int main() {
  hittable_list world;

  world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
  world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

  camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width  = 400;
  cam.samples_per_pixel = 100;

  cam.render(world);
}