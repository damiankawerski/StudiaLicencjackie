use crate::randgen::RandGen;

#[derive(Clone)]
pub struct Urna<T: Clone> {
    generator: RandGen,
    znaki: Vec<T>,
}

impl<T: Clone> Urna<T> {
    pub fn new(generator: RandGen) -> Self {
        Self {
            generator,
            znaki: Vec::new(),
        }
    }

    pub fn losuj_z_us(&mut self) -> Option<T> {
        if self.znaki.is_empty() {
            return None;
        }

        let index = self.generator.gen_range(0, (self.znaki.len() - 1) as i64) as usize;
        Some(self.znaki.remove(index))
    }

    pub fn losuj_bez_us(&mut self) -> Option<T> {
        if self.znaki.is_empty() {
            return None;
        }

        let index = self.generator.gen_range(0, (self.znaki.len() - 1) as i64) as usize;
        Some(self.znaki[index].clone())
    }

    pub fn rozmiar(&self) -> usize {
        self.znaki.len()
    }

    pub fn doloz(&mut self, znak: T) {
        self.znaki.push(znak);
    }
}
