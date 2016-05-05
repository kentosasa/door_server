require 'sinatra'
require 'sinatra/reloader'
require 'arduino_firmata'

get '/' do
  arduino = ArduinoFirmata.connect ARGV.shift
  5.times do
    angle = rand 180
    puts angle
    arduino.servo_write 13, angle
    sleep 1
  end
end

get '/open' do
 arduino = ArduinoFirmata.connect ARGV.shift
 angle = 180
  puts 'open'
  arduino.servo_write 13, angle
  "open door"
end

get '/close' do
 arduino = ArduinoFirmata.connect ARGV.shift
 angle = 0
  puts 'close'
  arduino.servo_write 13, angle
  "close door"
end

get '/exit' do
 Process.kill('TERM', Process.pid)
end
