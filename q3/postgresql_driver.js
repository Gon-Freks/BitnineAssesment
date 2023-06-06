const { Pool } = require('pg');

// Function to execute a SQL query and return the result as JSON string
async function executeQuery(query) {
    const pool = new Pool({
        user: 'postgres',
        host: 'localhost',
        database: 'postgres',
        password: '1234',
        port: 5432, 
      });
      
    const client = await pool.connect();

  try {
    const result = await client.query(query);
    const data = result.rows;
    const jsonResult = {
      status_code: 200,
      data: data
    };
    return JSON.stringify(jsonResult);
  } catch (error) {
    console.error('Error executing query:', error);
    throw error;
  } finally {
    client.release();
  }
}

module.exports = {
  executeQuery
};
