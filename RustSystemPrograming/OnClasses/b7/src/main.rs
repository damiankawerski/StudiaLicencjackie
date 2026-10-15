struct Matrix {
    mat: Vec<Vec<f64>>,
}


impl Matrix {
    fn new(height: usize, width: usize, content: f64) -> Matrix {
        let mat = vec![vec![content;width]; height];
        Matrix { mat }
    }

    fn zeros(height: usize, width: usize) -> Matrix {
        Self::new(height, width, 0.0)
    }

    fn identity(height: usize) -> Matrix {
        let mut mat = Self::zeros(height, height);
        for i in 0..mat.mat.len() {
            for j in 0..mat.mat[i].len() {
                if i == j {
                    mat.mat[i][j] = 1.0;
                } 
            }
        }
        return mat
    }

    fn get_element(&self, i: usize, j: usize) -> f64 {
        if i < self.mat.len() && j < self.mat[i].len() {
            return self.mat[i][j];
        } 
        -1.0
    }

    fn set_element(&mut self, i: usize, j: usize, value: f64) {
        if i < self.mat.len() && j < self.mat[i].len() {
            self.mat[i][j] = value;
        } 
    }

    fn sum(mat1: &Self, mat2: &Self) -> Matrix {
        let mut result = Self::zeros(mat1.mat.len(), mat1.mat[0].len());
        for i in 0..mat1.mat.len() {
            for j in 0..mat1.mat[i].len() {
                result.set_element(i, j, mat1.get_element(i, j) + mat2.get_element(i, j));
            }
        }
        result
    }

    fn show(&self) {
        for i in 0..self.mat.len() {
            for j in 0..self.mat[i].len() {
                print!("{:?} ", self.mat[i][j]);
            }
            println!();
        }
    }

}


fn test_new_matrix() -> bool {
    let m = Matrix::new(2, 2, 3.0);
    m.get_element(0, 0) == 3.0 && m.get_element(1, 1) == 3.0 && m.get_element(0, 1) == 3.0 && m.get_element(1, 0) == 3.0
}

fn test_zeros_matrix() -> bool {
    let z = Matrix::zeros(3, 3);
    z.get_element(0, 0) == 0.0 && z.get_element(2, 2) == 0.0 && z.get_element(1, 1) == 0.0
}

fn test_identity_matrix() -> bool {
    let id = Matrix::identity(3);
    for i in 0..3 {
        for j in 0..3 {
            let expected = if i == j { 1.0 } else { 0.0 };
            if id.get_element(i, j) != expected {
                return false;
            }
        }
    }
    true
}

fn test_sum_matrix() -> bool {
    let m1 = Matrix::new(2, 2, 1.0);
    let m2 = Matrix::new(2, 2, 2.0);
    let sum = Matrix::sum(&m1, &m2);
    for i in 0..2 {
        for j in 0..2 {
            if sum.get_element(i, j) != 3.0 {
                return false;
            }
        }
    }
    true
}

fn test_set_get_element() -> bool {
    let mut m = Matrix::zeros(2, 2);
    m.set_element(0, 1, 9.9);
    (m.get_element(0, 1) - 9.9).abs() < 1e-9
}

fn main() {
    println!("test_new_matrix: {}", test_new_matrix());
    println!("test_zeros_matrix: {}", test_zeros_matrix());
    println!("test_identity_matrix: {}", test_identity_matrix());
    println!("test_sum_matrix: {}", test_sum_matrix());
    println!("test_set_get_element: {}", test_set_get_element());
    let m1 = Matrix::new(2, 2, 1.0);
    m1.show();
}
