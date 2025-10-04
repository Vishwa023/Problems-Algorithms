// ************** Without Mutex **************

// asyncTask started 1001, count: 0
// incrementCount started 1001, count: 0
// incrementCount increment completed 1001, count: 1
// asyncTask started 1002, count: 1
// incrementCount started 1002, count: 1
// incrementCount increment completed 1002, count: 2
// main completed
// asyncTask completed 1001, count: 2
// asyncTask completed 1002, count: 2


// ************** With Mutex **************

// asyncTask started 1001, count: 0
// incrementCount started 1001, count: 0
// incrementCount increment completed 1001, count: 1
// asyncTask completed 1001, count: 1
// asyncTask started 1002, count: 1
// incrementCount started 1002, count: 1
// incrementCount increment completed 1002, count: 2
// asyncTask completed 1002, count: 2


const Mutex = require('async-mutex').Mutex

let count = 0

const mutex = new Mutex()

const asyncTask = async (threadId) => {
  const release = await mutex.acquire()
  try {
  console.log(`asyncTask started ${threadId}, count: ${count}`)
  await incrementCount(threadId)
  console.log(`asyncTask completed ${threadId}, count: ${count}`)
  } catch (error) {
    console.error(`asyncTask error ${threadId}, count: ${count}`)
  } finally {
    release()
  }
}

const incrementCount = async (threadId) => {
  console.log(`incrementCount started ${threadId}, count: ${count}`)
  count++
  console.log(`incrementCount increment completed ${threadId}, count: ${count}`)
}

async function main() {
  await Promise.all([asyncTask(1001), asyncTask(1002)])
}

main()