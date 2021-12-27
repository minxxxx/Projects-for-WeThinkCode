# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rails db:seed command (or created alongside the database with db:setup).
#
# Examples:
#
#   movies = Movie.create([{ name: 'Star Wars' }, { name: 'Lord of the Rings' }])
#   Character.create(name: 'Luke', movie: movies.first)
User.new(name: "toto", email: "hh@gmail.com", password: "test1234").save
User.new(name: "bernard", email: "hh@gmail.com", password: "42424242").save
User.new(name: "admin", email: "hh@gmail.com", password: "root").save
