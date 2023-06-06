const { executeQuery } = require('./postgresql_driver');

// Example usage
async function main() {
  const query = 'SELECT * FROM public.user_table;';
  try {
    const result = await executeQuery(query);
    console.log('Result:', result);
  } catch (error) {
    console.error('Error:', error);
  }
}

main();
