#[derive(PartialEq)]
struct Rgb {
    red: u8,
    green: u8,
    blue: u8,
}

impl Rgb {
    fn new() -> Rgb {
        Rgb { red: 255, green: 255, blue: 255 }
    }

    fn from_3u8(red: u8, green: u8, blue: u8) -> Rgb {
        Rgb { red, green, blue }
    }

    fn get_proportions(percent: f32) -> u8 {
        (2.55 * percent) as u8
    }
    

    fn from_3percent(red_p: f32, green_p: f32, blue_p: f32) -> Option<Rgb> {
        if !(0.0..=100.0).contains(&red_p) ||
           !(0.0..=100.0).contains(&green_p) ||
           !(0.0..=100.0).contains(&blue_p) {
            return None;
        }

        let red = Self::get_proportions(red_p);
        let green = Self::get_proportions(green_p);
        let blue = Self::get_proportions(blue_p);

        Some(Rgb {red, green, blue})
    }

    fn gray(percent: f32) -> Option<Rgb>{
        Rgb::from_3percent(percent, percent, percent)
    }

    fn white() -> Rgb {
        Rgb::new()
    }

    fn black() -> Rgb {
        Rgb::from_3u8(0, 0, 0)
    }

    fn invert(&mut self) {
        self.red = 255 - self.red;
        self.green = 255 - self.green;
        self.blue = 255 - self.blue;
    }
    
    fn intensity(&self) -> f32 {
        let sum = self.red as f32 + self.green as f32 + self.blue as f32;
        sum / (3.0 * 255.0)
    }

    fn as_rgb_u8tuple(&self) -> (u8, u8, u8) {
        return (self.red, self.green, self.blue)
    }
    
    fn as_cmy_u8tuple(&self) -> (u8, u8, u8) {
        (255 - self.red, 255 - self.green, 255 - self.blue)
    }

}



// impl PartialEq for Rgb {
//     fn eq(&self, other: &Self) -> bool{
//         self.red == other.red && self.blue == other.blue && self.green == other.green
//     }
// }




fn main() {
    let szary1 = Rgb::from_3u8(127, 127, 127);
    let szary2 = Rgb::from_3percent(50.0, 50.0, 50.0).unwrap();
    let szary3 = Rgb::gray(50.0).unwrap();
    let fiolet = Rgb::from_3u8(100, 35, 120);
    let bialy1 = Rgb::white();
    let bialy2 = Rgb::from_3u8(255, 255, 255);
    let mut czarny1 = Rgb::black();
    let czarny2 = Rgb::from_3u8(0, 0, 0);
    println!("{} {}", szary1 == szary2, szary1 == szary3);
    println!("{} {}", bialy1 == bialy2, czarny1 == czarny2);
    czarny1.invert();
    println!("{}", bialy1 == czarny1);
    println!("{}", fiolet.intensity() == 1.0/3.0);
    println!("{}", fiolet.as_rgb_u8tuple() == (100, 35, 120));
    println!("{}", fiolet.as_cmy_u8tuple() == (155, 220, 135));
}