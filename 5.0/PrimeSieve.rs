fn main() {
  let (n, q) = get_initial_input();
  let mut primes = init_vec(n);
  set_primes(n, &mut primes);

  let total_primes = primes.iter().filter(|&b| *b).count();
  println!("{}", total_primes);

  for i in 0..q {
    let query = get_query();
    if primes[query as usize] {
      println!("1");
    } else {
      println!("0")
    }
  }
}

fn get_initial_input() -> (u32, u32) {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec = input.split_whitespace().map(|x| x.parse::<u32>().expect("parse error")).collect::<Vec<u32>>();

  (vec[0], vec[1])
}

fn get_query() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
 
  input.trim().parse().expect("wanted a number")
}

fn set_primes(ceil: u32, primes: &mut Vec<bool>) {
  let mut p: u32 = 2;
  loop {
    if p*p > ceil {
      break;
    }

    if primes[p as usize] == true {
      let mut i: u32 = p*p;
      loop {
        if i > ceil {
          break;
        }
        primes[i as usize] = false;
        i += p;
      }
    }

    p += 1;
  }
}

fn init_vec(ceil: u32) -> Vec<bool> {
  let mut vec: Vec<bool> = Vec::new();
  vec.push(false);
  vec.push(false);
  for _ in 2..ceil+1 {
    vec.push(true);
  }

  vec
}
