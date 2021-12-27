class CreateUsers < ActiveRecord::Migration
  def change
    create_table :users do |t|
      t.string :name
      t.string :email
      t.datetime :created_at
      t.datetime :updated_at
      t.integer :since
      t.boolean :admin
      t.string :country
    end
  end
end
