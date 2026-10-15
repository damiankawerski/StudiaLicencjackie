
// zadanie 1
fn swap(a: &mut i32, b: &mut i32) {
    let temp = *a;
    *a = *b;
    *b = temp;
}

// zadanie 2
fn sort_3_values(a: &mut i32, b: &mut i32, c: &mut i32) {
    if *a > *b {
        swap(a, b);
    }
    if *b > *c {
        swap(b, c);
    }
    if *a > *b {
        swap(a, b);
    }

}

// zadanie 3
fn rand(seed: &mut u64, min_rand: u64, max_rand: u64) -> u64 {
    let a: u64 = 1664525;
    let c: u64 = 1013904223;
    let m: u64 = u64::MAX;

    *seed = (a.wrapping_mul(*seed).wrapping_add(c)) % m;

    min_rand + (*seed % (max_rand - min_rand + 1))
}

// zadnaie 4
fn swap_arr(arr: &mut [u64], i: usize, j: usize) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

fn rand_perm(arr: &mut [u64], seed: &mut u64) {
    for i in 0..arr.len() {
        let rand_index = rand(seed, i as u64, (arr.len() - 1) as u64);
        swap_arr(arr, i, rand_index as usize);
    }

}

fn main() {

    let mut seed = 123456789;
    let mut arr: [u64; 10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    println!("{:?}", arr);
    rand_perm(&mut arr, &mut seed);
    println!("{:?}", arr);

}