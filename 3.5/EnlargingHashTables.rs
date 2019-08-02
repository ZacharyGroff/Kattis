fn main() {
  let (largest, inputs) = get_inputs();
  let prime_vec = get_primes((largest*2) + 8350);
  for input in inputs {
    //pass ref here
    let closest_prime = find_closest_prime(n*2, primes);
    if is_prime(input) {
      println!("{}", closest_prime);
    } else {
      println!("{} ({} is not prime)", closest_prime, input);
    }
  }
}

fn get_inputs() -> (u32, Vec<u32>) {
  let mut largest: u32 = 0;
  let mut inputs: Vec<u32> = Vec::new();
  loop {
    let input = get_input_line();
    if input == 0 {
      break
    }

    if largest < input {
      largest = input;
    }

    inputs.push(input);
  }

  (largest, inputs)
}

fn get_input_line() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");

  input.trim().parse().expect("wanted a number")
}

fn get_primes(ceil: u32) {

}

fn is_prime(n: u32) -> bool {

}

fn find_closest_prime(n: u32, primes: Vec<u32>) -> u32 {

}
