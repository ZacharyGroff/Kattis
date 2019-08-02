fn main() {
  loop {
    let (inp1, inp2) = get_input();
    if inp1 == 0 && inp2 == 0 {
      break;
    }
    let carries = calculate_carries(inp1, inp2);
    print_test_case(carries);
  }
}

fn get_input() -> (u32, u32) {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec = input.split_whitespace().map(|x| x.parse::<u32>().expect("parse error")).collect::<Vec<u32>>();

  (vec[0], vec[1])
}

fn calculate_carries(mut inp1: u32, mut inp2: u32) -> u8 {
  let mut current_carry = 0 as u8;
  let mut total_carries = 0;
  while (inp1 > 0 && inp2 > 0) || current_carry > 0 {
    current_carry = calculate_carry(inp1 % 10, inp2 % 10, current_carry);
    if current_carry > 0 {
      total_carries += 1;
    }

    inp1 /= 10;
    inp2 /= 10;
  }

  total_carries
}

fn calculate_carry(inp1: u32, inp2: u32, current_carry: u8) -> u8 {
  (((inp1 + inp2 + current_carry as u32) / 10 ) % 10) as u8
}

fn print_test_case(carries: u8) {
  if carries == 0 {
    println!("No carry operation.");
  } else if carries == 1 {
    println!("{} carry operation.", carries);
  } else {
    println!("{} carry operations.", carries);
  }
}
