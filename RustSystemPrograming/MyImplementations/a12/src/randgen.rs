#[derive(Debug, Clone, Copy)]
pub struct RandGen {
    seed: i64,
}

impl RandGen {
    pub fn new(seed: i64) -> RandGen {
        RandGen { seed }
    }

    pub fn gen_range(&mut self, min: i64, max: i64) -> i64 {
        if min > max {
            panic!("min > max.");
        }

        let a: i64 = 1664525;
        let c: i64 = 1013904223;
        let m: i64 = i64::MAX;

        self.seed = self
            .seed
            .wrapping_mul(a)
            .wrapping_add(c)
            .rem_euclid(m);

        let zakres = (max - min + 1).max(1);
        min + self.seed.rem_euclid(zakres)
    }
}