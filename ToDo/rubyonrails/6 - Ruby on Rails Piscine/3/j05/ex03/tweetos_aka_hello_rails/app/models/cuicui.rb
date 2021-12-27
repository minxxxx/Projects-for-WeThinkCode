class Cuicui < ActiveRecord::Base
  belongs_to :user
  has_many :users, through: :likes
  has_many :users, through: :comments
  has_many :comments
  has_many :likes
end
