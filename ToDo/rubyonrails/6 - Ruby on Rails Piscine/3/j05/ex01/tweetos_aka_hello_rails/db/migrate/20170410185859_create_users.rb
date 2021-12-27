class CreateUsers < ActiveRecord::Migration
  def change
    create_table :users do |t|
      t.string :name
      t.string :email
      t.integer :since
      t.boolean :admin
      t.string :country

      t.timestamps null: false
    end
  end
end
