class Book < ApplicationRecord
  validates_uniqueness_of :name
end
