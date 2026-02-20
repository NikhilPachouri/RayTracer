class sphere : public hittable {
  public:

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const {
    

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_front_face(r, outward_normal);
        
        return true;
    }

};